#include <htmldecode/htmldecode.h>
#include "catch_runner.h"

using namespace std;

TEST_CASE("Simple sentences with HTML entities")
{
    REQUIRE(HtmlDecode("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s")
            ==
            "Cat <says> \"Meow\". M&M\'s");

    REQUIRE(HtmlDecode("I'll &quot;walk&quot; the &lt;b&gt;dog&lt;/b&gt; now")
            ==
            "I'll \"walk\" the <b>dog</b> now");
}

TEST_CASE("HTML entities on both ends")
{
    REQUIRE(HtmlDecode("&amp;ABC&quot;") == "&ABC\"");
}

TEST_CASE("Incomplete/invalid html entities")
{
    REQUIRE(HtmlDecode("&am&amp&amp ;A&quo t; t; quot; &quot;")
            ==
            "&am&amp&amp ;A&quo t; t; quot; \"");

    REQUIRE(HtmlDecode("&&&&&&....&;") == "&&&&&&....&;");
    REQUIRE(HtmlDecode("&&&&&&&&&&") == "&&&&&&&&&&");
    REQUIRE(HtmlDecode("&amp;lt;") != "<");
}

TEST_CASE("Empty string shouldn't be modified at all")
{
    REQUIRE(HtmlDecode("") == "");
}

TEST_CASE("Single '&' character shouldn't loop the function")
{
    REQUIRE(HtmlDecode("&") == "&");
}

TEST_CASE("Spaces")
{
    REQUIRE(HtmlDecode("   ") == "   ");
}

TEST_CASE("Should successfully replace escaped entity in the middle of unescaped ones")
{
    REQUIRE(HtmlDecode("&&&amp;&&&") == "&&&&&&");
}

TEST_CASE("Shuffle entities (replacement shouldn't go wrong because of std::unordered_map's order of entities)")
{
    REQUIRE(HtmlDecode("&amp;&gt;&lt;&apos;&quot;")
            ==
            "&><'\"");

    REQUIRE(HtmlDecode("&quot;&apos;&lt;&gt;&amp;")
            ==
            "\"'<>&");

    REQUIRE(HtmlDecode("&lt;&quot;&amp;&apos;&gt;")
            ==
            "<\"&'>");
}