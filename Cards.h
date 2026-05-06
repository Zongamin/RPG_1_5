#ifndef CARDS_H
#define CARDS_H

#include <string>
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
            if (value >= Value::Bube && value < Value::Ass) return 10;
            if (value == Value::Ass) return 11;
            return static_cast<int>(value);
        }
        std::string getSymbol() const 
        {
            switch (color)
            {
                case Color::Herz:  return "♥";
                case Color::Karo:  return "♦";
                case Color::Pik:   return "♠";
                case Color::Kreuz: return "♣";
                default:           return "?";
            }
        }
        std::string getValueString() const 
        {
            switch (value)
            {
                case Value::Zwei:   return "2";
                case Value::Drei:   return "3";
                case Value::Vier:   return "4";
                case Value::Fuenf:  return "5";
                case Value::Sechs:  return "6";
                case Value::Sieben: return "7";
                case Value::Acht:   return "8";
                case Value::Neun:   return "9";
                case Value::Zehn:   return "10";
                case Value::Bube:   return "B";
                case Value::Dame:   return "D";
                case Value::Koenig: return "K";
                case Value::Ass:    return "A";
                default:            return "?";
            }
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
                for (int value = 2; value <= 13; value++)
                {
                    cards.push_back({(Color)color, (Value)value});
                }
            }
        }

        void shuffle() 
        {
            std::shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));
        }

        void deckReset() 
        {
            cards.clear();

            for (int color = 0; color < 4; color++)
            {
                for (int value = 2; value <= 13; value++)
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