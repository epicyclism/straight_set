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

	public:
		using key_type = Key;
		using value_type = decltype(set_::value_type);
		using size_type = decltype(set_::size_type);
		using difference_type = decltype(set_::difference_type);
		using key_equal = std::equal<Key>;
		using reference = value_type & ;
		using const_reference = const value_type&;
		using iterator = decltype(set_::iterator);
		using const_iterator = decltype(set_::const_iterator);

		straight_set()
		{
			if constexpr (RESERVE > 0)
				set_.reserve(RESERVE);
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
		auto rbegin()
		{
			return std::rbegin(set_);
		}
		auto rend()
		{
			return std::rend(set_);
		}
		auto rcbegin() const
		{
			return std::crbegin(set_);
		}
		auto crend() const
		{
			return std::crend(set_);
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
			std::copy(std::begin(iL), std::end(iL), std::back_inserter(set_));
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
		auto size() const
		{
			return set_.size();
		}
		auto empty() const
		{
			return set_.empty();
		}
		auto max_size() const noexcept
		{
			return set_.max_size();
		}
		auto insert(T const& t)
		{
			auto ip = find(t);
			if (ip == end())
			{
				ip = set_.insert(end(), t);
				return std::make_pair(ip, true);
			}
			return std::make_pair(ip, false);
		}
	};
}
