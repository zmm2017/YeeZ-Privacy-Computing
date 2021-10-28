#pragma once
#include <hpda/processor/processor_base.h>

namespace hpda {
namespace processor {
namespace internal {
template <typename InputObjType>
class concat_impl : public processor_base<InputObjType, InputObjType> {
public:
  typedef processor_base<InputObjType, InputObjType> base;
  concat_impl(
      ::hpda::internal::processor_with_output<InputObjType> *upper_stream)
      : processor_base<InputObjType, InputObjType>(upper_stream) {
    m_upper_streams.push_back(upper_stream);
    m_index;
  }

  void add_upper_stream(
      ::hpda::internal::processor_with_output<InputObjType> *upper_stream) {
    m_upper_streams.push_back(upper_stream);
    base::add_predecessor(upper_stream);
  }
  virtual bool process() {
    while (m_index < m_upper_streams.size() &&
           !m_upper_streams[m_index]->has_value()) {
      m_index++;
    }
    if (m_index >= m_upper_streams.size()) {
      return false;
    }
    return m_upper_streams[m_index]->has_value();
  }

  virtual InputObjType output_value() {
    return m_upper_streams[m_index]->output_value();
  }

protected:
  typedef ::hpda::internal::processor_with_output<InputObjType> upper_stream_t;
  size_t m_index;
  std::vector<upper_stream_t *> m_upper_streams;
};
} // namespace internal
template <typename... ARGS>
using concat = internal::concat_impl<ntobject<ARGS...>>;
} // namespace processor
} // namespace hpda
