#include "Surface.h"
#include <Awesomium\Surface.h>
//#include <Awesomium\BitmapSurface.h>
#include <iostream>

void TestSurface::Paint(unsigned char *src_buffer, int src_row_span, const Awesomium::Rect &src_rect, const Awesomium::Rect &dest_rect){


		//glDeleteTextures(1, &textureID);

		//unsigned char *buffer = new unsigned char[src_rect.width * src_rect.height * 4];
		//surface->CopyTo(buffer, src_rect.width * 4, 4, false, false);

			GLuint textureID;

			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			// build our texture mipmaps
			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, src_rect.width,src_rect.height, GL_RGBA, GL_UNSIGNED_BYTE, src_buffer);
			//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,src_rect.width, src_rect.height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, src_buffer);

			std::cout << "WORKING!!!";


	}


void Awesomium::Surface::Paint(unsigned char *src_buffer, int src_row_span, const Awesomium::Rect &src_rect, const Awesomium::Rect &dest_rect){


		//glDeleteTextures(1, &textureID);

		//unsigned char *buffer = new unsigned char[src_rect.width * src_rect.height * 4];
		//surface->CopyTo(buffer, src_rect.width * 4, 4, false, false);

			GLuint textureID;

			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			// build our texture mipmaps
			//gluBuild2DMipmaps(GL_TEXTURE_2D, 4, src_rect.width,src_rect.height, GL_RGBA, GL_UNSIGNED_BYTE, src_buffer);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,src_rect.width, src_rect.height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, src_buffer);

			std::cout << "WORKING!!!";


	}


void TestSurface::Scroll (int dx, int dy, const Awesomium::Rect &clip_rect){


}

Awesomium::Surface*  TestFactory::CreateSurface (Awesomium::WebView *view, int width, int height){

	std::cout << "Custom surface";
	TestSurface* surface;

	surface = (TestSurface*)view->surface();

	return (Awesomium::Surface*)surface;

}

Awesomium::Surface* Awesomium::SurfaceFactory::CreateSurface (Awesomium::WebView *view, int width, int height){

	std::cout << "Custom surface";
	TestSurface* surface;

	surface = (TestSurface*)view->surface();

	return (Awesomium::Surface*)surface;

}

/*
Awesomium::Surface* TestFactory::CreateSurface(Awesomium::WebView *view, int width, int height){

	TestSurface* surface;

	surface = (TestSurface*)view->surface();

	return (Awesomium::Surface*)surface;
}*/


void TestFactory::DestroySurface(Awesomium::Surface *surface){



}

