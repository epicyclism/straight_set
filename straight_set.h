// straight_set.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vector>
#include <algorithm>

namespace epicyclism
{
	template <
		class Key, 
		int RESERVE = 0 
	> class straight_set
	{
	private:
		std::vector<Key> set_;
		template<typename Ref> auto insert_(Ref t)
		{
			auto ip = find(t);
			if (ip == end())
			{
				ip = set_.insert(end(), t);
				return std::make_pair(ip, true);
			}
			return std::make_pair(ip, false);
		}
		template<typename ft> void insert1_(ft const& t)
		{
			auto ip = find(t);
			if (ip == end())
			{
				set_.insert(end(), t);
			}
		}

	public:
		using key_type = Key;
		using value_type = Key;
		using size_type = size_t;
//		using key_equal = std::equal<Key>;
		using reference = value_type & ;
		using const_reference = const value_type&;
		using iterator = typename std::vector<Key>::iterator;
		using const_iterator = typename std::vector<Key>::const_iterator;

		straight_set()
		{
			if constexpr (RESERVE > 0)
				set_.reserve(RESERVE);
		}
		straight_set(straight_set const& other)
		{
			set_ = other.set_;
		}
		straight_set(std::initializer_list<value_type> iL)
		{
			insert(std::begin(iL), std::end(iL));
		}
		auto begin() const
		{
			return std::begin(set_);
		}
		auto end() const
		{
			return std::end(set_);
		}
		auto begin()
		{
			return std::begin(set_);
		}
		auto end()
		{
			return std::end(set_);
		}
		auto cbegin() const
		{
			return std::cbegin(set_);
		}
		auto cend() const
		{
			return std::cend(set_);
		}
		auto operator=(const straight_set& other)
		{
			set_ = other.set_;
			return *this;
		}
		auto operator=(straight_set&& other) noexcept
		{
			set_ = other.set_;
			return *this;
		}
		auto operator=(std::initializer_list<value_type> iL)
		{
			set_.clear();
			insert1_(std::begin(iL), std::end(iL));
			return *this;
		}
		auto find(Key& k)
		{
			return std::find(begin(), end(), k);
		}
		auto find(Key const& k) const
		{
			return std::find(cbegin(), cend(), k);
		}
		auto empty() const
		{
			return set_.empty();
		}
		auto size() const
		{
			return set_.size();
		}
		auto max_size() const noexcept
		{
			return set_.max_size();
		}
		void clear() noexcept
		{
			set_.clear();
		}
		auto insert(value_type const& t)
		{
			return insert_(t);
		}
		auto insert(value_type && t)
		{
			return insert_(t);
		}
		template<typename InIt> void insert(InIt first, InIt last)
		{
			while (first != last)
			{
				insert1_(*first);
				++first;
			}
		}
		template<typename InIt> void insert(std::initializer_list<value_type> iL)
		{
			insert(std::begin(iL), std::end(iL));
		}
		template<class... Args> auto emplace(Args&&... args)
		{
			auto ip = find(t);
			if (ip == end())
			{
				ip = set_.emplace_back(args);
				return std::make_pair(ip, true);
			}
			return std::make_pair(ip, false);
		}
		auto erase(const_iterator pos)
		{
			return set_.erase(pos);
		}
		auto erase(const key_type& k)
		{
			auto ip = find(k);
			if (ip != set_.end())
			{
				set_.erase(ip);
				return 1;
			}
			return 0;
		}
		void swap(straight_set& other)
		{
			set_.swap(other.set_);
		}

	};
}
