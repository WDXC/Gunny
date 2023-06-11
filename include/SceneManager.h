#ifndef _GUNNY_SCENEMANAGER_H_
#define _GUNNY_SCENEMANAGER_H_

#include <memory>
#include <queue>
#include <string>
#include <unordered_map>

#include "Scene.h"

namespace Gunny {
class SceneManager {
public:
  SceneManager();
  void addScene(const std::string &name, std::shared_ptr<Scene> scene);
  void activateScene(const std::string &name);
  void removeScene(const std::string &name);
  void onEvent(const SDL_Event &event);
  void update(const unsigned int delta);
  void draw() const;

private:
  std::unordered_map<std::string, std::shared_ptr<Scene>> scene;
  std::queue<std::shared_ptr<Scene>> removedScenes;
  std::shared_ptr<Scene> currentScene = nullptr;
};
} // namespace Gunny

#endif
