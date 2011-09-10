#ifndef BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_TRAITS_STATUS_MESSAGE_HPP_20100903
#define BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_TRAITS_STATUS_MESSAGE_HPP_20100903

// Copyright Dean Michael Berris 2010.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

namespace boost { namespace network { namespace http {
    
    namespace traits {

        template <class Tag>
        struct unsupported_tag;

        template <class Message>
        struct status_message
        : mpl::if_<
            is_async<typename Message::tag>,
            boost::shared_future<typename string<typename Message::tag>::type>,
            typename mpl::if_<
                mpl::or_<
                    is_sync<typename Message::tag>,
                    is_same<typename Message::tag, tags::default_string>,
                    is_same<typename Message::tag, tags::default_wstring>
                >,
                typename string<typename Message::tag>::type,
                unsupported_tag<typename Message::tag>
            >::type
        >
        {};

    } /* traits */

} /* http */
} /* network */
} /* boost */

#endif

