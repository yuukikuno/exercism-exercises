use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &'a [&str]) -> HashSet<&'a str> {
    let mut word_chars = word.to_lowercase().chars().collect::<Vec<char>>();
    word_chars.sort();
    let mut result: HashSet<&str> = HashSet::new();
    for possible_anagram in possible_anagrams {
        let mut possible_anagram_chars = possible_anagram
            .to_lowercase()
            .chars()
            .collect::<Vec<char>>();
        possible_anagram_chars.sort();
        if possible_anagram_chars == word_chars
            && word.to_lowercase() != possible_anagram.to_lowercase()
        {
            result.insert(possible_anagram);
        }
    }
    result
}
