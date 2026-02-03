#include <iterator>

namespace my {

template <typename InputIterator, typename OutputIterator>
void copy(InputIterator first1, InputIterator last1, OutputIterator first2) {
    for (; first1 != last1; ++first1, ++first2) {
        *first2 = *first1;
    }
}

template <typename InputIterator>
InputIterator find(InputIterator first, InputIterator last, const typename std::iterator_traits<InputIterator>::value_type& value) {
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }

    return last;
}

template <typename InputIterator, typename Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate p) {
    for (; first != last; ++first) {
        if (p(*first)) {
            return first;
        }
    }

    return last;
}

template <typename InputIterator, typename T>
T accumulate(InputIterator first, InputIterator last, T init) {
    for (; first != last; ++first) {
        init += *first;
    }

    return init;
}

template <typename InputIterator, typename T, typename BinaryOp>
T accumulate(InputIterator first, InputIterator last, T init, BinaryOp op){
    for (; first != last; ++first) {
        init = op(init, *first);
    }

    return init;    
}

template<typename InputIterator>
InputIterator search(InputIterator first, InputIterator last, InputIterator s_first, InputIterator s_last){
    if(s_first == s_last){
        return last;
    }

    for(; first != last; ++first){
        InputIterator tmp_first = first;
        InputIterator tmp_s_first = s_first;       

        while(tmp_first != last && tmp_s_first != s_last && *tmp_first == *tmp_s_first){
            ++tmp_first;
            ++tmp_s_first;
        }

        if(tmp_s_first == s_last){
            return first;
        }
    }

    return last;
} 

template<typename InputIterator>
InputIterator adjacent_find(InputIterator first, InputIterator last){
    if(first == last){
        return last;
    }

    for(; first != last; ++first){
        InputIterator first_next = first;
        ++first_next;
        if( first_next != last && *first == *(first_next)){
            return first;
        }
    }
    return last;
}

template<typename InputIterator, typename BinaryPred>
InputIterator adjacent_find(InputIterator first, InputIterator last, BinaryPred pred){
    if(first == last){
        return last;
    }

    for(; first != last; ++first){
        InputIterator first_next = first;
        ++first_next;
        if( first_next != last && pred(*first, *first_next)){
            return first;
        }
    }
    return last;    
}

template<typename InputIterator>
typename std::iterator_traits<InputIterator>::difference_type count(InputIterator first, InputIterator last, typename std::iterator_traits<InputIterator>::value_type value){
    typename std::iterator_traits<InputIterator>::difference_type count = 0;
    for(; first != last; ++first){
        if(*first == value){
            ++count;
        }
    }
    return count;
}

template<typename InputIterator, typename UnaryPred>
typename std::iterator_traits<InputIterator>::difference_type count_if(InputIterator first, InputIterator last, UnaryPred p){
    typename std::iterator_traits<InputIterator>::difference_type count = 0;
    for(; first != last; ++first){
        if(p(*first)){
            ++count;
        }
    }
    return count;    
}

//Modifying algorithms

template<typename ForwardIterator, typename Generator>
void generate(ForwardIterator first, ForwardIterator last, Generator g){
    for(; first != last; ++first){
        *first = g();
    }
}

template<typename InputIterator, typename OutputIterator, typename UnaryOperator>
OutputIterator transform(InputIterator first1, InputIterator last1, OutputIterator first2, UnaryOperator up){
    for(; first1 != last1; ++first1, ++first2){
        *first2 = up(*first1);
    }
    return first2;
}

template<typename InputIterator, typename OutputIterator, typename BinaryOperator>
OutputIterator transform(InputIterator first1, InputIterator last1, InputIterator first2, OutputIterator first3, BinaryOperator up){
    for(; first1 != last1; ++first1, ++first2, ++first3){
        *first3 = up(*first1, *first2);
    }
    return first3;    
}

template<typename ForwardIterator>
void replace(ForwardIterator first, ForwardIterator last, 
        typename std::iterator_traits<ForwardIterator>::value_type oldVal, typename std::iterator_traits<ForwardIterator>::value_type newVal){
            for(; first != last; ++first){
                if(*first == oldVal){
                    *first = newVal;
                }
            }
        }

template<typename ForwardIterator, typename UnaryPred>
void replace_if(ForwardIterator first, ForwardIterator last, UnaryPred up, typename std::iterator_traits<ForwardIterator>::value_type newVal){
            for(; first != last; ++first){
                if(up(*first)){
                    *first = newVal;
                }
            }
}

template<typename ForwardIterator>
ForwardIterator remove(ForwardIterator first, ForwardIterator last, typename std::iterator_traits<ForwardIterator>::value_type val){
    ForwardIterator tmp = first;
    for(; first != last; ++first){
        if(*first != val){
            *tmp = *first;
            ++tmp;
        }
    }
    return tmp;
}

template <typename ForwardIterator, typename UnaryPred>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, UnaryPred up){
    ForwardIterator tmp = first;
    for(; first != last; ++first){
        if(!(up(*first))){
            *tmp = *first;
            ++tmp;
        }
    }
    return tmp;   
}

template<typename BidirectIterator>
void reverse(BidirectIterator first, BidirectIterator last) {
    while (first != last) {
        --last;
        if(last == first){
            break;
        }
        typename std::iterator_traits<BidirectIterator>::value_type tmp = *first;
        *first = *last;
        *last = tmp;
        ++first;
    }
}


}// namespace my
