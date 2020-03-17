# CS-389-HW3
## Jonah Kohn and Elijah Wheelock

In order to confirm the functionality of the Cache projects from Hw2, we built a series of tests based on TDD fundamentals. The tests are written to be used by the Catch/2 library, which provides an incredibly insightful view into the source of test failures. The tests are written to confirm the functionality of the Cache and Evictor modules, based on the API given by Eitan. Tests are designed to probe a single element of the Cache functionality, and are standalone functions. For all three of our testing volunteers, we had no issues compiling or linking the files. The results from our own personal testing as well as the volunteer tests are outlined in the charts below:


#### Elijah and Jonah's Cache:
| **Cache Tests**      | **Description**                                                             | Pass/Fail |
| -------------        |:--------------------------------------------------------------------------- |:--------- |
| Clean Slate          | Cache::get on empty cache returns nullptr                                   | Pass      |
| Basic Fetching       | Cache::get returns the value set for the key                                | Pass      |
| Deep vs Shallow copy | Cache::set performs a deep copy                                             | Pass      |
| Tracking used Space  | Successive sets to different keys increase space_used                       | Pass      |
| Updating Size        | Cache::get updates its second argument to the size of the requested element | Pass      |
| Exceeding Capacity   | Insertions that would go over max_size fail                                 | Pass      |
| Overwriting Values   | Subsequent writes to same key overwrite                                     | Pass      |
| Oversized Elements   | Elements larger than max_size are not inserted                              | Pass      |
| Deleting Nothing     | Cache::del fails on non-inserted keys                                       | Pass      |
| True Deletion        | Cache::del renders the deleted element inaccessible                         | Pass      |
| True Reset           | Cache::reset renders all elements inaccessible, zeroes space_used           | Pass      |
| **Evictor Tests**    | **Description**                                                             |           |
| Clean Slate          | Evicting on an empty evictor should return an empty string                  | Pass      |
| Order 1              | Evicting after touching a key should return that key                        | Pass      |
| Order 2              | Insertion order should be respected in eviction order                       | Pass      |
| Duplicates           | Insertion order should be respected in eviction order, even with duplicates | Pass      |
| Emptying             | Emptying the cache between insertions should not change behavior            | Pass      |


#### Arthur and Ian's Cache:
| **Cache Tests**      | **Description**                                                             | Pass/Fail |
| -------------        |:--------------------------------------------------------------------------- |:--------- |
| Clean Slate          | Cache::get on empty cache returns nullptr                                   | Fail      |
| Basic Fetching       | Cache::get returns the value set for the key                                | Pass      |
| Deep vs Shallow copy | Cache::set performs a deep copy                                             | Pass      |
| Tracking used Space  | Successive sets to different keys increase space_used                       | Pass      |
| Updating Size        | Cache::get updates its second argument to the size of the requested element | Pass      |
| Exceeding Capacity   | Insertions that would go over max_size fail                                 | Fail      |
| Overwriting Values   | Subsequent writes to same key overwrite                                     | Pass      |
| Oversized Elements   | Elements larger than max_size are not inserted                              | Fail      |
| Deleting Nothing     | Cache::del fails on non-inserted keys                                       | Pass      |
| True Deletion        | Cache::del renders the deleted element inaccessible                         | Fail      |
| True Reset           | Cache::reset renders all elements inaccessible, zeroes space_used           | Fail      |
| **Evictor Tests**    | **Description**                                                             |           |
| Clean Slate          | Evicting on an empty evictor should return an empty string                  | Pass      |
| Order 1              | Evicting after touching a key should return that key                        | Pass      |
| Order 2              | Insertion order should be respected in eviction order                       | Pass      |
| Duplicates           | Insertion order should be respected in eviction order, even with duplicates | Fail      |
| Emptying             | Emptying the cache between insertions should not change behavior            | Pass      |


#### James and Reilly's Cache:
| **Cache Tests**      | **Description**                                                             | Pass/Fail |
| -------------        |:--------------------------------------------------------------------------- |:--------- |
| Clean Slate          | Cache::get on empty cache returns nullptr                                   | Pass      |
| Basic Fetching       | Cache::get returns the value set for the key                                | Pass      |
| Deep vs Shallow copy | Cache::set performs a deep copy                                             | Pass      |
| Tracking used Space  | Successive sets to different keys increase space_used                       | Pass      |
| Updating Size        | Cache::get updates its second argument to the size of the requested element | Pass      |
| Exceeding Capacity   | Insertions that would go over max_size fail                                 | Pass      |
| Overwriting Values   | Subsequent writes to same key overwrite                                     | Pass      |
| Oversized Elements   | Elements larger than max_size are not inserted                              | Pass      |
| Deleting Nothing     | Cache::del fails on non-inserted keys                                       | Pass      |
| True Deletion        | Cache::del renders the deleted element inaccessible                         | Pass      |
| True Reset           | Cache::reset renders all elements inaccessible, zeroes space_used           | Pass      |
| **Evictor Tests**    | **Description**                                                             |           |
| Clean Slate          | Evicting on an empty evictor should return an empty string                  | Pass      |
| Order 1              | Evicting after touching a key should return that key                        | Pass      |
| Order 2              | Insertion order should be respected in eviction order                       | Pass      |
| Duplicates           | Insertion order should be respected in eviction order, even with duplicates | Pass      |
| Emptying             | Emptying the cache between insertions should not change behavior            | Pass      |


#### Liam and Weihang's Cache:
| **Cache Tests**      | **Description**                                                             | Pass/Fail |
| -------------        |:--------------------------------------------------------------------------- |:--------- |
| Clean Slate          | Cache::get on empty cache returns nullptr                                   | Pass      |
| Basic Fetching       | Cache::get returns the value set for the key                                | Fail      |
| Deep vs Shallow copy | Cache::set performs a deep copy                                             | Pass      |
| Tracking used Space  | Successive sets to different keys increase space_used                       | Pass      |
| Updating Size        | Cache::get updates its second argument to the size of the requested element | Fail      |
| Exceeding Capacity   | Insertions that would go over max_size fail                                 | Pass      |
| Overwriting Values   | Subsequent writes to same key overwrite                                     | Fail      |
| Oversized Elements   | Elements larger than max_size are not inserted                              | Pass      |
| Deleting Nothing     | Cache::del fails on non-inserted keys                                       | Pass      |
| True Deletion        | Cache::del renders the deleted element inaccessible                         | Pass      |
| True Reset           | Cache::reset renders all elements inaccessible, zeroes space_used           | Pass      |
| **Evictor Tests**    | **Description**                                                             |           |
| Clean Slate          | Evicting on an empty evictor should return an empty string                  | Pass      |
| Order 1              | Evicting after touching a key should return that key                        | Pass      |
| Order 2              | Insertion order should be respected in eviction order                       | Pass      |
| Duplicates           | Insertion order should be respected in eviction order, even with duplicates | Fail      |
| Emptying             | Emptying the cache between insertions should not change behavior            | Pass      |

