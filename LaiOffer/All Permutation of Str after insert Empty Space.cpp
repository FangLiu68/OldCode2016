//
//  All Permutation of Str after insert Empty Space.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a string, we can insert at most one empty space between each pair of adjacent letters.  Print all permutations of strings after insertions of empty spaces.
 Input:  str[] = "ABC"
 Output:
	ABCv
	AB C
	        A BC
	        A B C
 public List<String> insertSpace(String input) {
 List<String> result;
 if (input == null || input.isEmpty()) {
 return result;
	}
	StringBuilder builder = new StringBuilder();
	dfs(input, 0, builder, result);
	return result;
 }
 private void dfs(String input, int index, StringBuilder builder, List<String> result) {
 if (index == input.length() - 1){
 result.add(builder.toString());
 return;
	}
	// case 1, add empty space after input.charAt(index);
 builder.append(input.charAt(index));
 builder.append(‘ ‘);
 dfs(input, index + 1, builder, result);
 builder.deleteCharAt(builder.length() - 1);
 builder.deleteCharAt(builder.length() - 1);
 // case 2, not add empty space
 builder.append(input.charAt(index));
 dfs(input, index + 1, builder, result);
 builder.deleteCharAt(builder.length() - 1);
 }

 */