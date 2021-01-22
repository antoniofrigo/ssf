#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "element/square.hpp"
#include "element/element.hpp"

Square::Square(SDL_Window * window): Element(window){}


template <class T> void Square::DrawElement(T &x, T &y, T &z){
  const GLchar* vertexSource = R"glsl(
    #version 150 core

    in vec2 position;
    uniform mat4 trans;
    void main()
    {
        gl_Position = trans * vec4(position, 0.0, 1.0);
    }
  )glsl";

  const GLchar* fragmentSource = R"glsl(
      #version 150 core

      out vec4 outColor;
      void main()
      {
          outColor = vec4(1.0, 1.0, 1.0, 1.0);
      }
  )glsl";

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  
  glm::mat4 trans = glm::mat4(1.0f);
  trans = glm::translate(trans, glm::vec3(x, y, z));

  GLfloat vertices[] = {
       0.01f,  0.01f,
       -0.01f, 0.01f,
       -0.01f, -0.01f,
       0.01f, -0.01f
  };

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glGenBuffers(1, &ebo);

  GLuint elements[] = {
    0, 1, 2,
    2, 3, 0
  };

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

  // Create and compile the vertex shader
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSource, NULL);
  glCompileShader(vertexShader);

  // Create and compile the fragment shader
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  glCompileShader(fragmentShader);

  // Link the vertex and fragment shader into a shader program
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glBindFragDataLocation(shaderProgram, 0, "outColor");
  glLinkProgram(shaderProgram);
  glUseProgram(shaderProgram);

  // Specify the layout of the vertex data
  GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

  GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
  glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  SDL_GL_SwapWindow(e_window);
}

void Square::Unload() {
  glDeleteProgram(shaderProgram);
  glDeleteShader(fragmentShader);
  glDeleteShader(vertexShader);

  glDeleteBuffers(1, &ebo);
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
}

