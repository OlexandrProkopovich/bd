#include <SFML/Graphics.hpp>

class button
{
public:
    float _width, _height;
    int _x_pos, _y_pos;
    int _text_size;
    std::string _font_string;
    std::string _button_text;

    sf::Color _color_button;
    sf::Color _color_text;
    sf::Font _font;

    sf::Text text;
    sf::RectangleShape _button;

    button(float width, float height, int x_pos, int y_pos, sf::Color color_button, sf::Color color_text, std::string font, std::string button_text, int text_size) : _width(width), _height(height), _x_pos(x_pos),
        _y_pos(y_pos), _color_button(color_button), _color_text(color_text), _font_string(font), _button_text(button_text), _text_size(text_size)
    {
        _button.setSize(sf::Vector2f(_width, _height));
        _button.setFillColor(_color_button);
        _button.setPosition(_x_pos, _y_pos);

        _font.loadFromFile(_font_string);

        text.setString(button_text);
        text.setFont(_font);
        text.setCharacterSize(_text_size);
        text.setPosition(x_pos + 10, y_pos + 10);
        text.setFillColor(color_text);

    }

};