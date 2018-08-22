# frozen_string_literal: true


# Part 1

# Define a method sum(array) that takes an array of integers
# as an argument and returns the sum of its elements.
# For an empty array it should return zero.
def sum(array)
  return 0 if array.empty?
  array.sum
end

# Define a method max_2_sum(array) which takes an array of integers
# as an argument and returns the sum of its two largest elements.
# For an empty array it should return zero.
# For an array with just one element, it should return that element.
def max_2_sum(array)
  return 0 if array.empty?
  return array[0] if array.length == 1
  array.sort!.reverse!
  array[0] + array[1]
end

# Define a method sum_to_n?(array, n) that takes an array of integers
# and an additional integer, n, as arguments and returns true
# if any two elements in the array of integers sum to n.
# sum_to_n?([], n) should return false for any value of n, by definition.
def sum_to_n?(array, n)
  return false if array.empty?
  match = array.combination(2).detect do |a, b|
    a + b == n
  end
  !match.nil?
end

# Part 2

# Define a method hello(name) that takes a string representing a name and
# returns the string "Hello, " concatenated with the name.
def hello(name)
  "Hello, #{name}"
end

# Define a method starts_with_consonant?(s) that takes a string and
# returns true if it starts with a consonant and false otherwise.
# (For our purposes, a consonant is any letter other than A, E, I, O, U.)
# NOTE: be sure it works for both upper and lower case and for non-letters!
def starts_with_consonant?(s)
  return false if s.empty?
  return false if /^[[:alpha:]]/.match(s).nil?
  /^[^aeiou]/i.match(s)
end

# Define a method binary_multiple_of_4?(s) that takes a string and
# returns true if the string represents a binary number that is a multiple of 4.
# NOTE: be sure it returns false if the string is not a valid binary number!
def binary_multiple_of_4?(s)
  return false if s.empty?
  return false if s =~ /[^01]/
  (s.to_i(2) % 4).zero?
end

# Part 3

class BookInStock
  # YOUR CODE HERE
end
