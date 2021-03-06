// Generated by gencpp from file udpcom/master2udp.msg
// DO NOT EDIT!


#ifndef UDPCOM_MESSAGE_MASTER2UDP_H
#define UDPCOM_MESSAGE_MASTER2UDP_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace udpcom
{
template <class ContainerAllocator>
struct master2udp_
{
  typedef master2udp_<ContainerAllocator> Type;

  master2udp_()
    : gamecase(0)
    , ball_dt(0.0)  {
    }
  master2udp_(const ContainerAllocator& _alloc)
    : gamecase(0)
    , ball_dt(0.0)  {
  (void)_alloc;
    }



   typedef int32_t _gamecase_type;
  _gamecase_type gamecase;

   typedef double _ball_dt_type;
  _ball_dt_type ball_dt;





  typedef boost::shared_ptr< ::udpcom::master2udp_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::udpcom::master2udp_<ContainerAllocator> const> ConstPtr;

}; // struct master2udp_

typedef ::udpcom::master2udp_<std::allocator<void> > master2udp;

typedef boost::shared_ptr< ::udpcom::master2udp > master2udpPtr;
typedef boost::shared_ptr< ::udpcom::master2udp const> master2udpConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::udpcom::master2udp_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::udpcom::master2udp_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace udpcom

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'udpcom': ['/home/robit/catkin_ws/src/udpcom/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::udpcom::master2udp_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::udpcom::master2udp_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::udpcom::master2udp_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::udpcom::master2udp_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::udpcom::master2udp_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::udpcom::master2udp_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::udpcom::master2udp_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fdf21c6ce21b43770f17c6be4b218bce";
  }

  static const char* value(const ::udpcom::master2udp_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfdf21c6ce21b4377ULL;
  static const uint64_t static_value2 = 0x0f17c6be4b218bceULL;
};

template<class ContainerAllocator>
struct DataType< ::udpcom::master2udp_<ContainerAllocator> >
{
  static const char* value()
  {
    return "udpcom/master2udp";
  }

  static const char* value(const ::udpcom::master2udp_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::udpcom::master2udp_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 gamecase\n\
float64 ball_dt\n\
";
  }

  static const char* value(const ::udpcom::master2udp_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::udpcom::master2udp_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.gamecase);
      stream.next(m.ball_dt);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct master2udp_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::udpcom::master2udp_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::udpcom::master2udp_<ContainerAllocator>& v)
  {
    s << indent << "gamecase: ";
    Printer<int32_t>::stream(s, indent + "  ", v.gamecase);
    s << indent << "ball_dt: ";
    Printer<double>::stream(s, indent + "  ", v.ball_dt);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UDPCOM_MESSAGE_MASTER2UDP_H
