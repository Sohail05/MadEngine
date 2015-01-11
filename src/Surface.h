#ifndef SURFACE_H
#define SURFACE_H

#include <Awesomium/Surface.h>
#include <gl\glew.h>

//original code from Awesomium's Webflow demo

class MadSurface {

  GLuint texture_id_;
  unsigned char* buffer_;
  int bpp_, rowspan_, width_, height_;
  bool needs_update_;

 public:

  MadSurface(int width, int height);
  virtual ~MadSurface();
  GLuint GetTexture() const;

  int width() const { return width_; }
  int height() const { return height_; }
  int size() const { return rowspan_ * height_; }

 protected:
  virtual void Paint(unsigned char* src_buffer,
                     int src_row_span,
                     const Awesomium::Rect& src_rect,
                     const Awesomium::Rect& dest_rect);

  virtual void Scroll(int dx,
                      int dy,
                      const Awesomium::Rect& clip_rect);

  void UpdateTexture();
};

class MadSurfaceFactory : public Awesomium::SurfaceFactory {
public:
  MadSurfaceFactory();

  virtual ~MadSurfaceFactory();

  virtual Awesomium::Surface* CreateSurface(Awesomium::WebView* view,
                                            int width,
                                            int height);

  virtual void DestroySurface(Awesomium::Surface* surface);
};

#endif 