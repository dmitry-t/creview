#pragma once

#include "hints/net/request_handler.h"

namespace hints {
namespace net {

typedef std::function<RequestHandler*()> RequestHandlerFactory;

} // namespace net
} // namespace hints
