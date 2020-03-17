# CS-389-HW3
## Jonah Kohn and Elijah Wheelock

*Eitan granted us a two-day extension for this assignment, due to the complications around recent campus news.*

In order to confirm the functionality of the Cache projects from Hw2, we built a series of tests based on TDD fundamentals. The tests are written to be used by the Catch2 library, which provides an insightful view into the source of test failures. The tests are written to confirm the functionality of the Cache and Evictor modules, based on the API given by Eitan. Tests are designed to probe a single element of the Cache or Evictor functionality, and are standalone functions aside from the common fixture object. For all three of our testing volunteers, we had no issues compiling or linking the files, besides the fact that each of us chose a different name for the object defined in fifo\_evictor.hh, and a few other minor naming tweaks. The results from our own personal testing as well as the volunteer tests are outlined in the charts below:

#### Elijah and Jonah's Cache:
| **Cache Tests**      | **Description**                                                             | Pass/Fail |
| -------------        |:--------------------------------------------------------------------------- |:--------- |
| Clean Slate          | Cache::get on empty cache returns nullptr                                   | Pass      |
| Basic Fetching       | Cache::get returns the value set for the key                                | Pass      |
| Deep vs Shallow copy | Cache::set performs a deep copy                                             | Pass      |
| Tracking used Space  | Successive sets to different keys increase space\_used                      | Pass      |
| Updating Size        | Cache::get updates its second argument to the size of the requested element | Pass      |
| Exceeding Capacity   | Insertions that would go over max\_size fail                                | Pass      |
| Overwriting Values   | Subsequent writes to same key overwrite                                     | Pass      |
| Oversized Elements   | Elements larger than max\_size are not inserted                             | Pass      |
| Deleting Nothing     | Cache::del fails on non-inserted keys                                       | Pass      |
| True Deletion        | Cache::del renders the deleted element inaccessible                         | Pass      |
| True Reset           | Cache::reset renders all elements inaccessible, zeroes space\_used          | Pass      |
| **Evictor Tests**    | **Description**                                                             |           |
| Clean Slate          | Evicting on an empty evictor should return an empty string                  | Pass      |
| Order 1              | Evicting after touching a key should return that key                        | Pass      |
| Order 2              | Insertion order should be respected in eviction order                       | Pass      |
| Duplicates           | Insertion order should be respected in eviction order, even with duplicates | Pass      |
| Emptying             | Emptying the cache between insertions should not change behavior            | Pass      |

#### Arthur and Ian's Cache:
To compile Arthur and Ian's code, we renamed "FIFO" to "FifoEvictor" at every occurrence.

| **Cache Tests**      | **Description**                                                             | Pass/Fail |
| -------------        |:--------------------------------------------------------------------------- |:--------- |
| Clean Slate          | Cache::get on empty cache returns nullptr                                   | Fail      |
| Basic Fetching       | Cache::get returns the value set for the key                                | Pass      |
| Deep vs Shallow copy | Cache::set performs a deep copy                                             | Pass      |
| Tracking used Space  | Successive sets to different keys increase space\_used                      | Pass      |
| Updating Size        | Cache::get updates its second argument to the size of the requested element | Pass      |
| Exceeding Capacity   | Insertions that would go over max\_size fail                                | Fail      |
| Overwriting Values   | Subsequent writes to same key overwrite                                     | Pass      |
| Oversized Elements   | Elements larger than max\_size are not inserted                             | Fail      |
| Deleting Nothing     | Cache::del fails on non-inserted keys                                       | Pass      |
| True Deletion        | Cache::del renders the deleted element inaccessible                         | Fail      |
| True Reset           | Cache::reset renders all elements inaccessible, zeroes space\_used          | Fail      |
| **Evictor Tests**    | **Description**                                                             |           |
| Clean Slate          | Evicting on an empty evictor should return an empty string                  | Pass      |
| Order 1              | Evicting after touching a key should return that key                        | Pass      |
| Order 2              | Insertion order should be respected in eviction order                       | Pass      |
| Duplicates           | Insertion order should be respected in eviction order, even with duplicates | Fail      |
| Emptying             | Emptying the cache between insertions should not change behavior            | Pass      |


#### James and Reilly's Cache:
To compile James and Reilly's code, we renamed "Fifo\_Evictor" to "FifoEvictor" at every occurrence.
| **Cache Tests**      | **Description**                                                             | Pass/Fail |
| -------------        |:--------------------------------------------------------------------------- |:--------- |
| Clean Slate          | Cache::get on empty cache returns nullptr                                   | Pass      |
| Basic Fetching       | Cache::get returns the value set for the key                                | Pass      |
| Deep vs Shallow copy | Cache::set performs a deep copy                                             | Pass      |
| Tracking used Space  | Successive sets to different keys increase space\_used                      | Pass      |
| Updating Size        | Cache::get updates its second argument to the size of the requested element | Pass      |
| Exceeding Capacity   | Insertions that would go over max\_size fail                                | Pass      |
| Overwriting Values   | Subsequent writes to same key overwrite                                     | Pass      |
| Oversized Elements   | Elements larger than max\_size are not inserted                             | Pass      |
| Deleting Nothing     | Cache::del fails on non-inserted keys                                       | Pass      |
| True Deletion        | Cache::del renders the deleted element inaccessible                         | Pass      |
| True Reset           | Cache::reset renders all elements inaccessible, zeroes space\_used          | Pass      |
| **Evictor Tests**    | **Description**                                                             |           |
| Clean Slate          | Evicting on an empty evictor should return an empty string                  | Pass      |
| Order 1              | Evicting after touching a key should return that key                        | Pass      |
| Order 2              | Insertion order should be respected in eviction order                       | Pass      |
| Duplicates           | Insertion order should be respected in eviction order, even with duplicates | Pass      |
| Emptying             | Emptying the cache between insertions should not change behavior            | Pass      |


#### Liam and Weihang's Cache:
To compile Liam and Weihang code, we renamed "Fifo\_evictor" to "FifoEvictor" at every occurrence. Additionally, 
we renamed "fifo\_evictor.h" to "fifo\_evictor.hh", to align with the specification from homework 2.

| **Cache Tests**      | **Description**                                                             | Pass/Fail |
| -------------        |:--------------------------------------------------------------------------- |:--------- |
| Clean Slate          | Cache::get on empty cache returns nullptr                                   | Pass      |
| Basic Fetching       | Cache::get returns the value set for the key                                | Fail      |
| Deep vs Shallow copy | Cache::set performs a deep copy                                             | Pass      |
| Tracking used Space  | Successive sets to different keys increase space\_used                      | Pass      |
| Updating Size        | Cache::get updates its second argument to the size of the requested element | Fail      |
| Exceeding Capacity   | Insertions that would go over max\_size fail                                | Pass      |
| Overwriting Values   | Subsequent writes to same key overwrite                                     | Fail      |
| Oversized Elements   | Elements larger than max\_size are not inserted                             | Pass      |
| Deleting Nothing     | Cache::del fails on non-inserted keys                                       | Pass      |
| True Deletion        | Cache::del renders the deleted element inaccessible                         | Pass      |
| True Reset           | Cache::reset renders all elements inaccessible, zeroes space\_used          | Pass      |
| **Evictor Tests**    | **Description**                                                             |           |
| Clean Slate          | Evicting on an empty evictor should return an empty string                  | Pass      |
| Order 1              | Evicting after touching a key should return that key                        | Pass      |
| Order 2              | Insertion order should be respected in eviction order                       | Pass      |
| Duplicates           | Insertion order should be respected in eviction order, even with duplicates | Fail      |
| Emptying             | Emptying the cache between insertions should not change behavior            | Pass      |

