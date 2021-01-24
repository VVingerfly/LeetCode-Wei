cmake_minimum_required(VERSION 3.1)

macro(add_answer arg)
    add_executable(${arg} ${arg}.cpp)
    set_property(TARGET ${arg} PROPERTY FOLDER "LeetCode")
endmacro(add_answer)


add_answer(Q1_TwoSum)
add_answer(Q2_AddTwoNums)
add_answer(Q3_LongestSubstring)
add_answer(Q4_MedianOfTwoSortedArrays)
add_answer(Q5_LongestPalindromicSubstring)
add_answer(Q6_ZigZagConversion)
add_answer(Q7_ReverseInteger)
# add_answer()

add_answer(Q11_ContainerWithMostWater)
add_answer(Q15_3Sum)


add_answer(Q14_LongestCommonPrefix)
add_answer(Q122_BestTimeToBuyAndSellStockII)
add_answer(Q350_IntersectionOfTwoArraysII)
