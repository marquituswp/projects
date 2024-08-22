import Header from './Header.jsx';
import Footer from './Footer.jsx';
import Food from './Food.jsx';
import Card from './Card.jsx';
// MODULE METHOD CSS
import Button from './Button/Button.jsx';

import Student from './Student.jsx';
import UserGreeting from './User.jsx';
import List from './List.jsx';

function App() {
  // return (
  //   <>
  //     <Header/>
  //     <Food/>
  //     <Food/>
  //     <Footer/>
  //   </>
  // );  
  // return(
  //   <>
  //     {/* <Card/>
  //     <Card/> */}
  //     <Button/>
  //   </>
  // );

  // return (
  //   <>
  //     <Student name='Marcos' age={23} isStudent = {true}/>
  //     <Student name='Luis' age={25} isStudent = {false}/>
  //     <Student/>
  //   </>
  // );

  // return (
  //   <>
  //     <UserGreeting isLoggedIn={true} username='Marcos'/>
  //     <UserGreeting isLoggedIn={false} username='Marta'/>
  //     <UserGreeting />
  //   </>
  // )

    const fruits = [{id: 1, name: 'apple', calories: 95}, 
                    {id: 2, name: 'banana', calories: 105}, 
                    {id: 3, name: 'orange', calories: 45}, 
                    {id: 4, name: 'coconut', calories: 159}, 
                    {id: 5, name: 'pineapple', calories: 37}];

    const vegetables = [{id: 1, name: 'carrot', calories: 41},
                        {id: 2, name: 'broccoli', calories: 55},
                        {id: 3, name: 'potato', calories: 77},
                        {id: 4, name: 'spinach', calories: 23},
                        {id: 5, name: 'cucumber', calories: 15}];

    return(
      <>
        {fruits.length > 0 && <List items={fruits} category = 'Fruits'/>}
        {vegetables.length > 0 && <List items={vegetables} category = 'Vegetables'/>}
      </>
    )
}

export default App
