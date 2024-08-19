// props and propTypes in React, and default props

import PropTypes from 'prop-types';

function Student(props){
    return (
        <div className="student">
            <p>Name: {props.name}</p>
            <p>Age: {props.age}</p>
            <p>Is student: {props.isStudent ? 'Yes' : 'No'}</p>
        </div>
    )
}

// proptypes, if is not the type that is expected, it will show a warning in the console
Student.propTypes = {
    name: PropTypes.string,
    age: PropTypes.number,
    isStudent: PropTypes.bool
}

// default props, if the prop is not passed, it will take the default value
Student.defaultProps = {
    name: 'Guest',
    age: 0,
    isStudent: false
}

export default Student;