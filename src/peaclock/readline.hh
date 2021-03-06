#ifndef READLINE_HH
#define READLINE_HH

#include "ob/term.hh"
namespace aec = OB::Term::ANSI_Escape_Codes;

#include <cstddef>

#include <string>
#include <vector>

class Readline
{
public:

  Readline();
  ~Readline();

  std::string operator()(std::string const& prompt_ref, bool& is_running);
  void add_history(std::string const& str);

private:

  int ctrl_key(int c) const;

  struct Prompt
  {
    std::string str {aec::wrap(":", aec::fg_white)};
  } _prompt;

  struct Input
  {
    std::size_t idx {0};
    std::size_t off {0};
    std::string buf;
    std::string str;
    std::string fmt;
  } _input;

  struct History
  {
    std::vector<std::string> val;
    std::size_t idx;
  } _history;
};

#endif // READLINE_HH
