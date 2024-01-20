# CbGraphics
How to set up your first project:
```c++
#include "Window.h"
#include "Utils.h"

int main() {
	glfwInit();

	Cobalt::Vec2 size = { 640, 480 };
	Window win("Cobalt Graphics", size.x, size.y);

	glewInit();

	Cobalt::Camera cam(win.GetGLFWwindow(), size);

	std::vector<Cobalt::GameObject*> objects;

  //Make sure to have two folders, one for textures and another named "Shaders"("Shaders will have your vert.glsl and frag.glsl files in them)
	objects.push_back(new Cobalt::GameObject("Rune", "Tex/Rune.png", FilteringMode::Nearest));

	cam.SetMatrix(objects, size);

	while (!glfwWindowShouldClose(win.GetGLFWwindow()))
	{
		/* Render here */
		glClearColor(1.f, 0.84f, 0.77f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwGetFramebufferSize(win.GetGLFWwindow(), &size.x, &size.y);

		// Update the projection matrix with the new window size
		framebuffer_size_callback(win.GetGLFWwindow(), size.x, size.y);

		cam.SetMatrix(objects, size);

		for (int i = 0; i < objects.size(); i++) 
		{
			objects[i]->Render();
			objects[i]->Update();
		}

		//cam.Move(player.obj->GetPosition().x, player.obj->GetPosition().y);

		cam.Update();

		/* Swap front and back buffers */
		glfwSwapBuffers(win.GetGLFWwindow());

		/* Poll for and process events */
		glfwPollEvents();
	}

	for (int i = 0; i < objects.size(); i++) {
		delete objects[i];
	}

	return 0;
};
```
To get some of the required files, go to the <b>Extras</b> branch of this repository.
