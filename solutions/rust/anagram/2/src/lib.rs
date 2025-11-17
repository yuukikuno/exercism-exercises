use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &'a [&str]) -> HashSet<&'a str> {
    let normalized_word = normalize(word);
    possible_anagrams
        .iter()
        .filter(|candidate| {
            normalize(candidate) == normalized_word
                && word.to_lowercase() != candidate.to_lowercase()
        })
        .copied()
        .collect()
}

fn normalize(word: &str) -> String {
    let mut chars: Vec<char> = word.to_lowercase().chars().collect();
    chars.sort();
    chars.into_iter().collect()
}
