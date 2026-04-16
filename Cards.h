#ifndef CARDS_H
#define CARDS_H

#include <vector>
#include <algorithm>
#include <random>

enum class Color { Herz, Karo, Pik, Kreuz };
enum class Value { Zwei = 2, Drei, Vier, Fuenf, Sechs, Sieben, Acht, Neun, Zehn, Bube, Dame, Koenig, Ass };

class Cards 
{
    public :
        Color color;
        Value value;

        int getValue() const
        {
            if (value >= Value::Bube) return 10;
            if (value == Value::Ass) return 11;
            return static_cast<int>(value);
        }
};

class Deck
{
    private :
        std::vector<Cards> cards;

    public :
        Deck()
        {
            for (int color = 0; color < 4; ++color)
            {
                for (int value = 2; value <= 14; value++)
                {
                    cards.push_back({(Color)color, (Value)value});
                }
            }
        }

        void shuffle() 
        {
            std::shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));
        }

        void cardReset() 
        {
            cards.clear();

            for (int color = 0; color < 4; color++)
            {
                for (int value = 2; value <= 14; value++)
                {
                    cards.push_back({(Color)color, (Value)value});
                }
            }
        }

        Cards draw()
        {
            Cards c = cards.back();
            cards.pop_back();
            return c;
        }
    };

#endif