//
// Created by Max on 01/02/2025.
//

#ifndef WET_5_UTILITIES_H
#define WET_5_UTILITIES_H

template <bool Condition, typename T, typename F>
struct Conditional;

template <typename T, typename F>
struct Conditional<true, T, F> {
    typedef T value;
};

template <typename T, typename F>
struct Conditional<false, T, F> {
    typedef F value;
};

template <bool Condition, int T, int F>
struct ConditionalInteger;

template <int T, int F>
struct ConditionalInteger<true, T, F> {
    static const int value = T;
};

template <int T, int F>
struct ConditionalInteger<false, T, F> {
    static const int value = F;
};



#endif //WET_5_UTILITIES_H
