#ifndef RENDERER_H_TERFUSTI
#define RENDERER_H_TERFUSTI

#include "Walnut/Image.h"

#include <glm/glm.hpp>

#include "Camera.h"
#include "Ray.h"

#include <memory>

class Renderer
{
public:
	Renderer() = default;

	void Render(const Camera& camera);
	void OnResize(std::uint32_t width, std::uint32_t height);


	std::shared_ptr<Walnut::Image> GetFinalImage() const { return m_FinalImage; }

private:
	glm::vec4 TraceRay(const Ray& ray);

private:
	std::shared_ptr<Walnut::Image> m_FinalImage{};
	std::uint32_t* m_ImageData{ nullptr };
	float m_LastRenderTime{ 0.0f };

};

#endif // !RENDERER_H_TERFUSTI
