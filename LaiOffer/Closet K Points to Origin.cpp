//
//  Closet K Points to Origin.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find closest k points to origin.
 point = <x, y>
 distance = sqrt(x^2 + y^2);
 public ArrayList<Point> findClosestK(Point[] points, int k)
 {
 ArrayList<Point> result = new ArrayList<Point>();
 if(points == null || points.length == 0)
 return result;
 PriorityQueue<Point> maxheap = new PriorityQueue<Point>(k,new Comparator<Point>()
 {
 @override
 public int compare(Point p1, Point p2)
 {
 if(distance(p1) == distance(p2))
 return 0;
 else if(distance(p1) < distance(p2))
 return 1;
 else
 return -1;
 }
 });
 for(int i = 0; i < points.length; i++)
 {
 if(i < k)
 {
 maxheap.offer(points[k]);
 }
 else if(distance(points[i]) < distance(maxheap.peek()))
 {
 maxheap.poll();
 maxheap.offer(points[i]);
 }
 }
 for(int i = k - 1; i >= 0; i--)
 {
 result.add(maxheap.poll());
 }
 return result;
 }
 public double distance(Point p)
 {
 return Math.sqrt(p.x * p.x + p.y * p.y);
 }

 */