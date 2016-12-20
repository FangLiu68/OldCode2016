//
//  Deep Iterator.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/16/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Write an iterator that, given a (potentially nested) collection will iterate over the contents of the collections in order. Thus, given a collection containning ((1, 3, 5), (4, 7, 3), ((2, 3), 4)) the deep iterator should return 1, 3, 5, 4, 7, 3, 2, 3, 4
 Example 1:
 Given the list [[1, 1], 2, [1, 1]]
 By calling next repeatedly until hasNext returns false, the order of elements returned by next shoudl be:
 [1, 1, 2, 1, 1]
 */