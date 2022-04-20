#include <catch2/catch.hpp>

#include "assignment/linked_list.hpp"  // LinkedList
#include "utils.hpp"                   // rand_array

using assignment::LinkedList;
using Catch::Equals;

SCENARIO("LinkedList::ReverseIterative") {

  SECTION("empty list") {
    auto list = LinkedList();

    CHECK(list.IsEmpty());
    CHECK(list.size() == 0);

    list.ReverseIterative();

    CHECK_FALSE(list.front().has_value());
    CHECK_FALSE(list.back().has_value());

    CHECK(list.as_vector().empty());
  }

  SECTION("list with one or more elements") {
    const int size = GENERATE(range(1, 50));
    auto arr = utils::rand_array(size, -500, 500, true);

    auto list = LinkedList(arr);

    CHECK(list.size() == size);

    // reverse
    list.ReverseIterative();

    REQUIRE(list.front().has_value());
    REQUIRE(list.back().has_value());

    CHECK(list.front().value() == arr.back());
    CHECK(list.back().value() == arr.front());

    std::reverse(arr.begin(), arr.end());

    CHECK_THAT(list.as_vector(), Equals(arr));

    // reverse back
    list.ReverseIterative();

    REQUIRE(list.front().has_value());
    REQUIRE(list.back().has_value());

    CHECK(list.front().value() == arr.back());
    CHECK(list.back().value() == arr.front());

    std::reverse(arr.begin(), arr.end());

    CHECK_THAT(list.as_vector(), Equals(arr));
  }
}

SCENARIO("LinkedList::ReverseRecursive") {

  SECTION("emtpy list") {
    auto list = LinkedList();

    CHECK(list.IsEmpty());
    CHECK(list.size() == 0);

    list.ReverseRecursive();

    CHECK_FALSE(list.front().has_value());
    CHECK_FALSE(list.back().has_value());

    CHECK(list.as_vector().empty());
  }

  SECTION("list with one or more elements") {
    const int size = GENERATE(range(1, 20));
    auto arr = utils::rand_array(size, -500, 500, true);

    auto list = LinkedList(arr);

    CHECK(list.size() == size);

    // reverse
    list.ReverseRecursive();

    REQUIRE(list.front().has_value());
    REQUIRE(list.back().has_value());

    CHECK(list.front().value() == arr.back());
    CHECK(list.back().value() == arr.front());

    std::reverse(arr.begin(), arr.end());

    CHECK_THAT(list.as_vector(), Equals(arr));

    // reverse back
    list.ReverseRecursive();

    REQUIRE(list.front().has_value());
    REQUIRE(list.back().has_value());

    CHECK(list.front().value() == arr.back());
    CHECK(list.back().value() == arr.front());

    std::reverse(arr.begin(), arr.end());

    CHECK_THAT(list.as_vector(), Equals(arr));
  }
}
