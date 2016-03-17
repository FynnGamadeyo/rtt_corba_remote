#include <boost/test/unit_test.hpp>
#include <rtt_corba_remote/Dummy.hpp>

using namespace rtt_corba_remote;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    rtt_corba_remote::DummyClass dummy;
    dummy.welcome();
}
