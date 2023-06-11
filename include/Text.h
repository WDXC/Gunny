#ifndef _GUNNY_TEXT_H_
#define _GUNNY_TEXT_H_

#include "Object.h"
#include <SDL_ttf.h>
#include <memory>
#include <string>

namespace Gunny {
class Text : public Object {
public:
    /**
     * @Synopsis  Contruct a new Text Object
     *
     * @Param font - SDL2_TTF font
     * @Param renderer - SDL2 renderer
     * @Param text - text to draw on the screen
     */
  Text(std::shared_ptr<TTF_Font> font, SDL_Renderer *renderer,
       const std::string &text);
  /**
   * @Synopsis  set the Text
   *
   * @Param text - text to draw on the screen
   */
  void setText(const std::string &text);
  /**
   * @Synopsis  set the color
   *
   * @Param color - color of the text
   */
  void setColor(const SDL_Color &color);

private:
  /**
   * @Synopsis  load the text to texture if text or color was changed
   */
  void loadText();
  std::shared_ptr<TTF_Font> font = nullptr;
  std::string text;
  SDL_Color color = {255, 255, 255, 255};
};

} // namespace Gunny

#endif
