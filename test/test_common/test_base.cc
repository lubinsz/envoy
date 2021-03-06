#include "test/test_common/test_base.h"

#include "common/common/assert.h"

#include "test/test_common/global.h"

namespace Envoy {

void TestListener::OnTestEnd(const ::testing::TestInfo& test_info) {
  // Check that all singletons have been destroyed.
  std::string active_singletons = Envoy::Test::Globals::describeActiveSingletons();
  RELEASE_ASSERT(active_singletons.empty(),
                 absl::StrCat("FAIL [", test_info.test_suite_name(), ".", test_info.name(),
                              "]: Active singletons exist:\n", active_singletons));
}

} // namespace Envoy
