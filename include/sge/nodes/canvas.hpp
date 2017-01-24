#ifndef __SGE_CANVAS_HPP
#define __SGE_CANVAS_HPP

#include <sge/nodes/position.hpp>
#include <sge/utils/vector.hpp>
#include <sge/utils/shape.hpp>

#include <functional>
#include <utility>

namespace sge
{
    using DrawRequest = std::pair<std::function<void (SDL_Renderer *)>, SDL_Color>;

    class CanvasNode : public PositionNode
    {
        using PositionNode::PositionNode;

        public:
            virtual std::vector<std::string> mro() const;

            virtual void ready();
            virtual void draw();
            
            void clear();
            void draw_point(Vector pos, SDL_Color color);
            void draw_line(Vector start, Vector end, SDL_Color color);
            void draw_rect(SDL_Rect rect, SDL_Color color);
            void draw_filled_rect(SDL_Rect rect, SDL_Color color);
            void draw_shape(const Shape &shape, SDL_Color color);
            void draw_filled_shape(const Shape &shape, SDL_Color color);

        private:
            std::vector<DrawRequest> requests;
    };
}

#endif /* __SGE_CANVAS_HPP */
