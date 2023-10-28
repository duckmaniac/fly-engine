#ifndef COLORS_H
#define COLORS_H

#include "SFML/Graphics/Color.hpp"

// Colors used in application.
struct Colors
{
    inline static const sf::Color WHITE = sf::Color(244, 242, 222);
    inline static const sf::Color BLACK = sf::Color(0, 0, 0);
    inline static const sf::Color YELLOW = sf::Color(233, 179, 132);
    inline static const sf::Color GREEN = sf::Color(124, 157, 150);
    inline static const sf::Color BLUE = sf::Color(161, 204, 209);

    inline static const sf::Color BACKGROUND = WHITE;
    inline static const sf::Color MESH_COLOR = BLACK;
};

#endif // COLORS_H