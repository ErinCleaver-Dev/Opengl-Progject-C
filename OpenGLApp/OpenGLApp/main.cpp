#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int errorMessageGLFW(std::string message) {
	std::cout << message;
	glfwTerminate();
	return 1;
}

int errorMessageGLEW(std::string message, GLFWwindow *mainWindow) {
	std::cout << message;
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
	return 1;
}

int main() {

	//Initalise GLFW
	if (!glfwInit()) {
		return errorMessageGLFW("The GLFW intialisation failed");
	} 

	int screenWidth = 1080;
	int screenHeight = 1600;

	std::cout << "Starting GLFW inialisation";

	// used to setup the glfw window properties
	// opengl verison is currenlty set to 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// sets up how open gl will treat the code
	// the core profile means no backwards compatibility 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// allows forward compatibility 
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// create a pointer to the main window
	GLFWwindow* mainWindow = glfwCreateWindow(screenWidth, screenHeight, "Open GL Project", NULL, NULL);

	if (!mainWindow) {
		return errorMessageGLFW("Failed to display window");
	}

	//Get Buffer size information

	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//Set the context for glew to use 
	glfwMakeContextCurrent(mainWindow);

	//Allow modern extension features 
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		return errorMessageGLEW("GLEW initialisation failed", mainWindow);
	}

	// Setup the viewport size 
	glViewport(0, 0, bufferWidth, bufferHeight);

	// loop unitl windows closed
	while (!glfwWindowShouldClose(mainWindow)) {
		// Get user events 
		glfwPollEvents();

		// Clear Window

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	return 0;
}