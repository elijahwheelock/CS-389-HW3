# CS-389-HW3
## Jonah Kohn and Elijah Wheelock


#### Elijah and Jonah's Cache:
| Test Name            | Description                                                                 | Pass/Fail |
| -------------        |:--------------------------------------------------------------------------- |:--------- |
| Clean Slate          | Cache::get on empty cache returns nullptr.                                  | Pass      |
| Basic Fetching       | Cache::get returns the value set for the key                                | Pass      |
| Deep vs Shallow copy | Cache::set performs a deep copy.                                            | Pass      |
| Tracking used Space  | Successive sets to different keys increase space_used.                      | Pass      |
| Updating Size        | Cache::get updates its second argument to the size of the requested element | Pass      |
| Exceeding Capacity   | Insertions that would go over max_size fail.                                | Pass      |
| Overwriting Values   | Subsequent writes to same key overwrite.                                    | Pass      |
| Oversized Elements.  | Elements larger than max_size are not inserted.                             | Pass      |
| Deleting Nothing     | Cache::del fails on non-inserted keys.                                      | Pass      |
| True Deletion        | Cache::del renders the deleted element inaccessible.                        | Pass      |
| True Reset           | Cache::reset renders all elements inaccessible, zeroes space_used.          | Pass      |

#### Elijah and Jonah's Evictor:
| Test Name     | Description                                                                  | Pass/Fail |
| ------------- |:---------------------------------------------------------------------------  |:--------- |
| Clean Slate   | Evicting on an empty evictor should return an empty string.                  | Pass      |
| Order 1       | Evicting after touching a key should return that key.                        | Pass      |
| Order 2       | Insertion order should be respected in eviction order.                       | Pass      |
| Duplicates    | Insertion order should be respected in eviction order, even with duplicates. | Pass      |
| Emptying      | Emptying the cache between insertions should not change behavior.            | Pass      |

