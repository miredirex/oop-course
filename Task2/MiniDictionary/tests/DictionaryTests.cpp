#include <dictionary/Dictionary.h>
#include "CatchRunner.h"

using namespace std;

TEST_CASE("SaveTranslation/GetTranslation tests")
{
    Dictionary dict;

    REQUIRE(dict.IsEmpty());

    SECTION("Modification of the translation string shouldn't affect the already stored word")
    {
        // Arrange
        string word = "Hello";
        string mutableTranslation = "Привет";
        string originalTranslation = mutableTranslation;

        // Act
        dict.SaveTranslation(word, mutableTranslation);
        mutableTranslation = "123";

        // Assert
        REQUIRE(originalTranslation != mutableTranslation);
        REQUIRE(*dict.GetTranslation(word) == originalTranslation);
    }

    SECTION("Dictionary returns std::nullopt if the translation doesn't exist")
    {
        // Arrange
        string word = "any";

        // Act
        optional<string> translation = dict.GetTranslation(word);

        // Assert
        REQUIRE(translation == nullopt);
    }

    SECTION("Dictionary returns std::nullopt if translation doesn't exist and dictionary is not empty")
    {
        // Arrange
        dict.SaveTranslation("word", "слово");
        dict.SaveTranslation("welcome", "добро пожаловать");

        // Act
        optional<string> translation1 = dict.GetTranslation("onion");
        optional<string> translation2 = dict.GetTranslation("other");
        optional<string> translation3 = dict.GetTranslation("random");
        optional<string> translationThatExists = dict.GetTranslation("welcome");

        // Assert
        REQUIRE(!dict.IsEmpty());

        REQUIRE(translation1 == nullopt);
        REQUIRE(translation2 == nullopt);
        REQUIRE(translation3 == nullopt);
        REQUIRE(translationThatExists != nullopt);
    }
}

TEST_CASE("Dictionary serialization/deserialization tests")
{
    Dictionary dict;

    REQUIRE(dict.IsEmpty());

    SECTION("When non-empty dictionary is SERIALIZED to stream, stream is not empty")
    {
        // Arrange
        dict.SaveTranslation("something", "что-то");

        // Act
        stringstream ss;
        dict.Serialize(ss);

        // Assert
        REQUIRE(ss.str() != "");
    }

    SECTION("When dictionary is DESERIALIZED from a non-empty istream, dictionary is not empty")
    {
        // Arrange
        stringstream ss("word:\ttranslation");

        // Act
        dict.Deserialize(ss, true);

        // Assert
        REQUIRE(!dict.IsEmpty());
    }

    SECTION("Empty istream won't be saved to the dictionary")
    {
        // Arrange
        stringstream ss("");

        // Act
        dict.Deserialize(ss, true);

        // Assert
        REQUIRE(dict.IsEmpty());
    }

    SECTION("istream with no delimiter won't be saved to the dictionary")
    {
        // Arrange
        stringstream ss("example пример");

        // Act
        dict.Deserialize(ss, true);

        // Assert
        REQUIRE(dict.IsEmpty());
    }
}