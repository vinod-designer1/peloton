//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// peloton_endpoint.h
//
// Identification: src/include/distributed/peloton_endpoint.h
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//


#pragma once

#include "wire/distributed/rpc_server.h"
#include "wire/distributed/peloton_service.h"

namespace peloton {
namespace networking {

#define PELOTON_ENDPOINT_ADDR "127.0.0.1:9000"
#define PELOTON_ENDPOINT_INTER "128.237.168.175:9000"
#define PELOTON_ENDPOINT_FILE "ipc:///tmp/echo.sock"
#define PELOTON_SERVER_PORT 9000

}  // namespace distributed
}  // namespace peloton