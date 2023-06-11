#ifndef _GUNNY_OBJECT_H_
#define _GUNNY_OBJECT_H_

#include <SDL.h>
#include <memory>

namespace Gunny {
class Object {
public:
  Object(SDL_Renderer *renderer);
  virtual ~Object();
  void setSize(const int width, const int height);
  void setPosition(const int x, const int y);
  void setClip(const int width, const int height, const int x, const int y);
  void attachToCamera(bool isAttached = true);
  int getWidth() const;
  int getHeight() const;
  int getPositionX() const;
  int getPositionY() const;
  const SDL_Rect &getRect() const;
  void setFlip(SDL_RendererFlip flip);
  virtual void update(const unsigned int delta);
  void draw(const SDL_Rect &camera) const;

protected:
  SDL_Renderer *renderer = nullptr;
  std::shared_ptr<SDL_Texture> texture = nullptr;
  SDL_Rect rect;
  SDL_Rect clip;
  SDL_RendererFlip flipping = SDL_FLIP_NONE;

private:
  bool isAttachedToCamera = true;
};
} // namespace Gunny

#endif
