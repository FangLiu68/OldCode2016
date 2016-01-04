//
//  Sort Integer.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a single computer with a single CPU and a single core, which has 2GB of memory and 1GB available for use, it also has two 100GB hard drives.
 How to sort 80GB integers of 64 bits.?
 */

/*
 设计题，先问interviewer，搞清楚模糊的点：
 objective:  system是干什么的
 functionality： 具体实现什么功能
 scalability: 要处理多大的问题size, 有多少机器/cluster

 Assumption 1: Let’s assume that all data is stored in one hard drive, with the other one totally empty.
 Assumption 2:  after sorting, we store the data into one hard drive only
 Assumption 3:  Ascending order or Descending?
 Assumption 4:  what is the data of the range.  any value is possible.

 160 chunks     0.5GB / Chunk          Can we use  QSort()

 Next step:          for each chunk, there are n elements.
 1
 2   12
 1234 (=2GB)
 3
 4  34
 12345678
 5
 6   56
 5678
 7
 8  78
 How many levels of merging         log(160)  * 80GB

 160-Way merge
 1
 2
 3
 4	   MIN_HEAP	→ solution:       80GB * log(160)
 5
 …
 160
 */

/*
 Q2   (Design)  Given a single computer with a single CPU and a single core, which has 2GB of memory and 1GB available for use, it also has two 100GB hard drives.
 How to sort 80GB integers of 64 bits.?


 Assumption1:  OS 64 bits
 Assumption2: ascending or descending order?
 Assumption3: was the data sorted in one single Hard Drive originally?

 不能1G memory to sort 1G data
 因为Merge sort需要N空间，quick sort近乎需要O(1)空间，但仍然还是需要多余空间来作recursion
 所以我们用1G memory来sort0.5G data

 1GB Memory to sort 0.5GB data

 Jingya: ok to use merge sort to sort 1GB data with 1GB memory
 youfan,

 80GB
 160 chunks and 0.5 GB Data per chunk
 1GB Memory to sort 0.5GB data

 Step1,  sort each chunk of 0.5 GB data with 1 GB memory
 Step2,  merge these 160 chunk of data.  (k-way merge)

 JIngya propose to use binary reduction way.

 chunk1
 chunk2       chunk12
 chunk 14
 chunk3
 chunk4      chunk34
 ⇒ chunk 1-160
 …..


 chunk160    chunk80			          total  column log_2(160)


 k way merge的两种
 两种的时间复杂度一样，但是第一种每次Merge都需要磁盘读写，第二种只需要放到heap里一次
 第二种更好


 chunk1  (2MB data)
 chunk2
 chunk3			min_heap of size 160⇒ final results
 
 ….
 chun160	
 

 */