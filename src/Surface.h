#ifndef  SURFACE_H
#define  SURFACE_H

#include <Awesomium\WebCore.h>
#include <GL\glew.h>



class TestSurface : public Awesomium::Surface{

public:
	GLuint textureID;

	 void Paint(unsigned char *src_buffer, int src_row_span, const Awesomium::Rect &src_rect, const Awesomium::Rect &dest_rect);
	 void Scroll (int dx, int dy, const Awesomium::Rect &clip_rect);

};





class TestFactory : public Awesomium::SurfaceFactory{

public:

	  Awesomium::Surface* CreateSurface(Awesomium::WebView *view, int width, int height);
	  void DestroySurface (Awesomium::Surface *surface);

};




#endif