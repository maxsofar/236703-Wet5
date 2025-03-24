//
// Created by Max on 01/02/2025.
//

#ifndef WET_5_LIST_H
#define WET_5_LIST_H



template <typename H, typename... T>
struct List {
    typedef H head;
    typedef List<T...> next;
    static const int size = 1 + sizeof...(T);
};

template <>
struct List<> {
    static const int size = 0;
};

template <typename T, typename List>
struct PrependList;

template <typename T, typename... Ts>
struct PrependList<T, List<Ts...> > {
    typedef List<T, Ts...> list;
};

template <int N, typename List>
struct GetAtIndex;

template <typename H, typename... T>
struct GetAtIndex<0, List<H, T...> > {
    typedef H value;
};

template <int N, typename H, typename... T>
struct GetAtIndex<N, List<H, T...> > {
    typedef typename GetAtIndex<N - 1, List<T...> >::value value;
};

template <int N, typename NewType, typename List>
struct SetAtIndex;

template <typename NewType, typename H, typename... T>
struct SetAtIndex<0, NewType, List<H, T...> > {
    typedef List<NewType, T...> list;
};

template <int N, typename NewType, typename H, typename... T>
struct SetAtIndex<N, NewType, List<H, T...> > {
    typedef typename PrependList<H, typename SetAtIndex<N - 1, NewType, List<T...> >::list>::list list;
};




#endif //WET_5_LIST_H
