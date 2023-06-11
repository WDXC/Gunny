#ifndef _GUNNY_ASSETMANAGER_H_
#define _GUNNY_ASSETMANAGER_H_

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <memory>
#include <string>
#include <unordered_map>

namespace Gunny {
enum class Texture : int {
  MenuBack,
  Stone,
  Grass,
  Brick,
  Player,
  Enemy1,
  Enemy2,
  Enemy3,
  Bomb,
  Explosion,
  Door
};

enum class MusicEnum : int { MainMenu, Level };

enum class SoundEnum : int { Win, Lose, Explosion };

struct EnumClassHash {
  template <typename T> std::size_t operator()(T t) const {
    return static_cast<std::size_t>(t);
  }
};

class AssetManager {
public:
  void load(SDL_Renderer *renderer);
  std::shared_ptr<TTF_Font> getFont() const;
  std::shared_ptr<SDL_Texture> getTexture(Texture texture);
  std::shared_ptr<Mix_Music> getMusic(MusicEnum music);
  std::shared_ptr<Mix_Chunk> getSound(SoundEnum sound);

private:
  void loadFont();
  void loadTexture(SDL_Renderer *renderer, Texture texture,
                   const std::string &filepath);
  void loadMusic(MusicEnum music, const std::string &filepath);
  void loadSound(SoundEnum sound, const std::string &filepath);

  std::shared_ptr<TTF_Font> font = nullptr;
  std::unordered_map<Texture, std::shared_ptr<SDL_Texture>, EnumClassHash>
      textures;
  std::unordered_map<MusicEnum, std::shared_ptr<Mix_Music>, EnumClassHash> musics;
  std::unordered_map<SoundEnum, std::shared_ptr<Mix_Chunk>, EnumClassHash> sounds;
};

} // namespace Gunny

#endif
