/*
 *  Copyright (c) 2015, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include "mcrouter/McrouterStackContext.h"

namespace facebook { namespace memcache {

class McReply;
class McRequest;

namespace mcrouter {

class proxy_t;

class ProxyRequestLogger {
 public:
  explicit ProxyRequestLogger(proxy_t* proxy)
    : proxy_(proxy) {
  }

  template <class Operation>
  void log(const McRequest& request,
           RequestClass requestClass,
           const McReply& reply,
           const int64_t startTimeUs,
           const int64_t endTimeUs,
           Operation);

  inline void logError(const McRequest& request,
                       RequestClass requestClass,
                       const McReply& reply);

 protected:
  proxy_t* proxy_;
};

}}}  // facebook::memcache::mcrouter

#include "ProxyRequestLogger-inl.h"
