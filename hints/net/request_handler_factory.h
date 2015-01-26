#pragma once

#include "hints/net/RequestHandler.h"

namespace hints {
namespace net {

typedef std::function<RequestHandler*()> RequestHandlerFactory;

} // namespace net
} // namespace hints
