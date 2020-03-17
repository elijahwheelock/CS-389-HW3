#include "fifo_evictor.h"
#include <algorithm>

FifoEvictor::FifoEvictor():
	key_queue_(new std::deque<key_type>())
	{}


FifoEvictor::~FifoEvictor() = default;

void FifoEvictor::touch_key(const key_type& key )
{
	// If the key is already in the queue, delete it.
	auto it = std::find(key_queue_->begin(), key_queue_->end(), key);
	if(it != key_queue_->end())
	{
		it = key_queue_->erase(it);
	}
	// Push the key to the end of the queue.
	key_queue_->push_back(key);
}
const key_type FifoEvictor::evict()
{

	if(key_queue_->empty())
	{
		return "";
	}
	// Get a copy of the evicted key
	auto const next = key_queue_->front();
	// Pop the key in the queue
	key_queue_->pop_front();
	return next;
	
}
