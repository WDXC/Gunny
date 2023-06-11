#include "Object.h"

namespace Gunny {
Object::Object(SDL_Renderer *_renderer) { this->renderer = _renderer; }

Object::~Object() {}

void Object::setSize(const int width, const int height) {
  rect.w = width;
  rect.h = height;
}

void Object::setPosition(const int x, const int y) {
  rect.x = x;
  rect.y = y;
}

void Object::setClip(const int width, const int height, const int x,
                     const int y) {
  clip.w = width;
  clip.h = height;
  clip.x = x;
  clip.y = y;
}

void Object::attachToCamera(bool isAttached) {
  this->isAttachedToCamera = isAttached;
}

int Object::getWidth() const { return rect.w; }

int Object::getHeight() const { return rect.h; }

int Object::getPositionX() const { return rect.x; }

int Object::getPositionY() const { return rect.y; }

const SDL_Rect &Object::getRect() const { return rect; }

void Object::setFlip(SDL_RendererFlip flip) { flipping = flip; }

void Object::update(const unsigned int /*delta*/) {}

void Object::draw(const SDL_Rect &camera) const {
  if (renderer != nullptr && texture != nullptr) {
    // change position according to camera
    SDL_Rect destrinationRect = rect;
    if (isAttachedToCamera) {
      destrinationRect.x -= camera.x;
      destrinationRect.y -= camera.y;
    }
    // draw on the screen
    SDL_RenderCopyEx(renderer, texture.get(), &clip, &destrinationRect, 0,
                     nullptr, flipping);
  }
}
} // namespace Gunny
