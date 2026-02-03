#ifndef MYALGOS_H
#define MYALGOS_H

#include <iterator>

namespace my {

template <typename InputIterator, typename OutputIterator>
void copy(InputIterator first1, InputIterator last1, OutputIterator first2);

template <typename InputIterator>
InputIterator find(InputIterator first, InputIterator last, const typename std::iterator_traits<InputIterator>::value_type& value);

template <typename InputIterator, typename Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate p);

template <typename InputIterator, typename T>
T accumulate(InputIterator first, InputIterator last, T init);

template <typename InputIterator, typename T, typename BinaryOp>
T accumulate(InputIterator first, InputIterator last, T init, BinaryOp op);

template<typename InputIterator>
InputIterator search(InputIterator first, InputIterator last, InputIterator s_first, InputIterator s_last);

template<typename InputIterator>
InputIterator adjacent_find(InputIterator first, InputIterator last);

template<typename InputIterator, typename BinaryPred>
InputIterator adjacent_find(InputIterator first, InputIterator last, BinaryPred pred);

template<typename InputIterator>
typename std::iterator_traits<InputIterator>::difference_type count(InputIterator first, InputIterator last, typename std::iterator_traits<InputIterator>::value_type value);

template<typename InputIterator, typename UnaryPred>
typename std::iterator_traits<InputIterator>::difference_type count_if(InputIterator first, InputIterator last, UnaryPred p );

//Modifying algorithms

template<typename ForwardIterator, typename Generator>
void generate(ForwardIterator first, ForwardIterator last, Generator g);

template<typename InputIterator, typename OutputIterator, typename UnaryOperator>
OutputIterator transform(InputIterator first1, InputIterator last1, OutputIterator first2, UnaryOperator up); 

template<typename InputIterator, typename OutputIterator, typename BinaryOperator>
OutputIterator transform(InputIterator first1, InputIterator last1, InputIterator first2, OutputIterator first3, BinaryOperator up);

template<typename ForwardIterator>
void replace(ForwardIterator first, ForwardIterator last, 
    typename std::iterator_traits<ForwardIterator>::value_type oldVal, typename std::iterator_traits<ForwardIterator>::value_type newVal);

template<typename ForwardIterator, typename UnaryPred>
void replace_if(ForwardIterator first, ForwardIterator last, UnaryPred up, typename std::iterator_traits<ForwardIterator>::value_type newVal); 

template<typename ForwardIterator>
ForwardIterator remove(ForwardIterator first, ForwardIterator last, typename std::iterator_traits<ForwardIterator>::value_type val);

template <typename ForwardIterator, typename UnaryPred>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, UnaryPred up);

template<typename BidirectIterator>
void reverse(BidirectIterator first, BidirectIterator last);

} // namespace my

#include "myalgos.impl.h"

#endif // MYALGOS_H