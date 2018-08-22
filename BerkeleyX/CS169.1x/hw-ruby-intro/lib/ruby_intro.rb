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

def hello(name)
  # YOUR CODE HERE
end

def starts_with_consonant? s
  # YOUR CODE HERE
end

def binary_multiple_of_4? s
  # YOUR CODE HERE
end

# Part 3

class BookInStock
  # YOUR CODE HERE
end
