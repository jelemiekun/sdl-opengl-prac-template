#pragma once
#include <iostream>
#include <glad/glad.h>
#include <unordered_map>
#include <string>

class Shader {
private:
	std::unordered_map<std::string, int> uniformLocationCache;

	enum class Shader_Type {
		None,
		Vertex,
		Fragment
	};

	std::string parsheShaderSource(const char* sourcePath, Shader_Type type);
	GLuint compileShader(GLuint shader_type, const char* source);
	bool usable;

private:
	void createProgram(GLuint& vertexShader, GLuint& fragmentShader);
	void validateProgram();
	int getUniformLocation(const std::string& name);

public:
	GLuint ID;

	Shader(const char* sourcePath);
	~Shader();

	void bind() const;
	void unbind() const;
	void setBool(const std::string& name, bool value);
	void setInt(const std::string& name, int value);
	void setFloat(const std::string& name, float value);
	void clean();
};