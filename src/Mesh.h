#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Shader.h"
#include <GL\glew.h>
#include <gtc\matrix_transform.hpp>
#include <glm.hpp>
#include <assimp\types.h>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	GLuint id;
	std::string type;
	aiString path;
};

class Mesh {
public:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	void Draw(Shader shader);

private:
	GLuint VBO, VAO, EBO;
	void setupMesh();
};