#include "Surface.h"
#include <iostream>

MadSurface::MadSurface(int width, int height) : texture_id_(0),
	buffer_(0), bpp_(4), rowspan_(0), width_(width), height_(height) {
		rowspan_ = width_ * bpp_;
		buffer_ = new unsigned char[rowspan_ * height_];
		needs_update_ = false;

		glGenTextures(1, &texture_id_);
		glBindTexture(GL_TEXTURE_2D, texture_id_);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0,bpp_ == 3 ? GL_RGB : GL_BGRA, GL_UNSIGNED_BYTE, buffer_);
}

MadSurface::~MadSurface() {
	glDeleteTextures(1, &texture_id_);
	delete[] buffer_;
}

GLuint MadSurface::GetTexture() const {
	const_cast<MadSurface*>(this)->UpdateTexture();

	return texture_id_;
}

void MadSurface::Paint(unsigned char* src_buffer,
					   int src_row_span,
					   const Awesomium::Rect& src_rect,
					   const Awesomium::Rect& dest_rect) {
						   for (int row = 0; row < dest_rect.height; row++)
							   memcpy(buffer_ + (row + dest_rect.y) * rowspan_ + (dest_rect.x * 4),
							   src_buffer + (row + src_rect.y) * src_row_span + (src_rect.x * 4),
							   dest_rect.width * 4);

						   needs_update_ = true;
}

void MadSurface::Scroll(int dx,
						int dy,
						const Awesomium::Rect& clip_rect) {
							if (abs(dx) >= clip_rect.width || abs(dy) >= clip_rect.height)
								return;

							if (dx < 0 && dy == 0) {
								// Area shifted left by dx
								unsigned char* tempBuffer = new unsigned char[(clip_rect.width + dx) * 4];

								for (int i = 0; i < clip_rect.height; i++) {
									memcpy(tempBuffer, buffer_ + (i + clip_rect.y) * rowspan_ +
										(clip_rect.x - dx) * 4, (clip_rect.width + dx) * 4);
									memcpy(buffer_ + (i + clip_rect.y) * rowspan_ + (clip_rect.x) * 4,
										tempBuffer, (clip_rect.width + dx) * 4);
								}

								delete[] tempBuffer;
							} else if (dx > 0 && dy == 0) {
								// Area shifted right by dx
								unsigned char* tempBuffer = new unsigned char[(clip_rect.width - dx) * 4];

								for (int i = 0; i < clip_rect.height; i++) {
									memcpy(tempBuffer, buffer_ + (i + clip_rect.y) * rowspan_ +
										(clip_rect.x) * 4, (clip_rect.width - dx) * 4);
									memcpy(buffer_ + (i + clip_rect.y) * rowspan_ + (clip_rect.x + dx) * 4,
										tempBuffer, (clip_rect.width - dx) * 4);
								}

								delete[] tempBuffer;
							} else if (dy < 0 && dx == 0) {
								// Area shifted down by dy
								for (int i = 0; i < clip_rect.height + dy ; i++)
									memcpy(buffer_ + (i + clip_rect.y) * rowspan_ + (clip_rect.x * 4),
									buffer_ + (i + clip_rect.y - dy) * rowspan_ + (clip_rect.x * 4),
									clip_rect.width * 4);
							} else if (dy > 0 && dx == 0) {
								// Area shifted up by dy
								for (int i = clip_rect.height - 1; i >= dy; i--)
									memcpy(buffer_ + (i + clip_rect.y) * rowspan_ + (clip_rect.x * 4),
									buffer_ + (i + clip_rect.y - dy) * rowspan_ + (clip_rect.x * 4),
									clip_rect.width * 4);
							}

							needs_update_ = true;
}

void MadSurface::UpdateTexture() {
	if (needs_update_) {
		glBindTexture(GL_TEXTURE_2D, texture_id_);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width_, height_,
			bpp_ == 3 ? GL_RGB : GL_BGRA, GL_UNSIGNED_BYTE,
			buffer_);
		needs_update_ = false;
	}
}


MadSurfaceFactory::MadSurfaceFactory() {
}

MadSurfaceFactory::~MadSurfaceFactory() {
	delete this;
}

Awesomium::Surface* MadSurfaceFactory::CreateSurface(Awesomium::WebView* view,int width,int height) {

	MadSurface* M = new MadSurface(width, height);

	Awesomium::Surface* surface = (Awesomium::Surface*)M;

	return surface;
}

void MadSurfaceFactory::DestroySurface(Awesomium::Surface* surface) {
	delete (MadSurface*)(surface);
}