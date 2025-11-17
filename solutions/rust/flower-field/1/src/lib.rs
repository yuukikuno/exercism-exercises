pub fn annotate(garden: &[&str]) -> Vec<String> {
    garden
        .iter()
        .enumerate()
        .map(|(row_index, row)| {
            row.as_bytes()
                .iter()
                .enumerate()
                .map(|(column_index, byte)| match byte {
                    b'*' => '*',
                    b' ' => count_adjacent_flowers(garden, row_index, column_index),
                    _ => panic!("Should not have other characters"),
                })
                .collect()
        })
        .collect()
}

fn count_adjacent_flowers(garden: &[&str], row_index: usize, column_index: usize) -> char {
    let count = garden[row_index.saturating_sub(1)..=(row_index + 1).min(garden.len() - 1)]
        .iter()
        .flat_map(|neighbor_row| {
            let bytes = neighbor_row.as_bytes();
            bytes[column_index.saturating_sub(1)..=(column_index + 1).min(bytes.len() - 1)].iter()
        })
        .filter(|x| **x == b'*')
        .count();
    match count {
        0 => ' ',
        _ => (b'0' + count as u8) as char,
    }
}
