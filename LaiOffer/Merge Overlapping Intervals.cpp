//
//  Merge Overlapping Intervals.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8} }. The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. Similarly {5, 7} and {6, 8} should be merged and become {5, 8}
 */


/*
public List<Interval> merge (List<Interval> intervals)
{
    if (intervals == null || intervals.size() == 0)
        return intervals;
    Comparator<Interval> cmp = new Comparator<Interval>()
    {
        public int compare (Interval i1, Interval i2)
        {
            if (i1.start == i2.start)
                return i1.end - i2.end;
            return i1.start - i2.start;
        }
    };
    Collections.sort (intervals, cmp);
    List<Interval> res = new ArrayList<Interval>();
    Interval in = intervals.get(0);
    for (int i = 1; i < intervals.size(); i++)
    {
        Interval tmp = intervals.get (i);
        if (in.end < tmp.start)
        {
            res.add (in);
            in = tmp;
        }
        else
        {
            in.end = Math.max (in.end, tmp.end);
        }
    }
    res.add (in);
    return res;
}
*/
